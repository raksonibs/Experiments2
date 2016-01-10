package example;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class webApp extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    System.out.println("helloworld!");
    System.out.println(req.getRemoteAddr());
    System.out.println(req.getRemotePort());
    System.out.println(req.getProtocol());
    System.out.println(req.getMethod());
    System.out.println(req.getQueryString());
    System.out.println(req.getParameter("name"));
    System.out.println(req.getContextPath());
    System.out.println(req.getRequestURL());
    System.out.println(req.getServletPath());
    
    System.out.println(req.getPathTranslated());
    System.out.println(req.getPathInfo());
    
    System.out.println(this.getServletContext().getContextPath());
  
    
    System.out.println("Approaching Redirect");
    
    if (req.getPathInfo() != null && req.getPathInfo().equals("/YorkBank")) {
      System.out.println("Redirecting");
      String  url = this.getServletContext().getContextPath() + "/Start";
      resp.sendRedirect(url);
    } else {
      System.out.println("Not Redirecting");
      resp.getWriter().println("Testing Tomcat");
    }
  
  }
  
}
