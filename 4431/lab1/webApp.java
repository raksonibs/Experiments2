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
    resp.getWriter().println("Testing Tomcat");
  }
  
}
